const CUS_URL = 'http://localhost:8080';
let dataHistory = [];
let chart = null;
const MAX_DATA_POINTS = 10;

const updateDashboard = () => {
    fetch(CUS_URL + "/api/data", {
        method: 'GET',
        mode: 'cors'
    })
        .then(res => {
            if (!res.ok) throw new Error(`Status: ${res.status}`);
            return res.json();
        })
        .then(data => {
            console.log(data)
            const controllerContainer = document.getElementById("controllerContainer");
            const modeSelector = document.getElementById("modeSelector");
            let waterLevel = Math.max(0, Math.min(100, Number(data.waterLevel)));

            if (data.state === "UNCONNECTED") {
                document.getElementById("waterLevelValue").textContent = "—";
                toggleInputs(true);
                modeSelector.style.display = "none";
                controllerContainer.style.display = "none";
            } else {
                document.getElementById("waterLevelValue").textContent = waterLevel;
                toggleInputs(false);
                modeSelector.style.display = "block";
                controllerContainer.style.display = (data.state === "AUTOMATIC") ? "none" : "block";

                dataHistory.push({ time: new Date(), waterLevel: waterLevel });
                if (dataHistory.length > MAX_DATA_POINTS) dataHistory.shift();

                plotDataHistory(dataHistory, document.getElementById('waterLevelTrend'));
            }

            document.getElementById("valveValue").textContent = data.valveValue;
            document.getElementById("connectionStatus").textContent = data.state;
            document.getElementById("controlTypeInput").value = data.state;
        })
        .catch(() => {
            document.getElementById("connectionStatus").textContent = "NOT AVAILABLE";
            toggleInputs(true);
            document.getElementById("modeSelector").style.display = "none";
            document.getElementById("controllerContainer").style.display = "none";
        });
};

const toggleInputs = (disabled) => {
    document.getElementById("controlTypeInput").disabled = disabled;
    document.getElementById("valveLevelInput").disabled = disabled;
    const btn = document.querySelector("#controllerForm button[type='submit']");
    if (btn) btn.disabled = disabled;
};

const plotDataHistory = (data, canvas) => {
    if (!canvas) return;
    const ctx = canvas.getContext('2d');

    const xValues = data.map(x => x.time.toLocaleTimeString());
    const yValues = data.map(y => y.waterLevel);

    if (!chart) {
        chart = new Chart(ctx, {
            type: "line",
            data: {
                labels: xValues,
                datasets: [{
                    label: "Water Level",
                    backgroundColor: "rgba(13, 110, 253, 0.1)",
                    borderColor: "rgba(13, 110, 253, 1)",
                    borderWidth: 2,
                    fill: true,
                    data: yValues,
                    tension: 0.4
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: false,
                animation: false,
                plugins: { legend: { display: false } },
                scales: {
                    y: { beginAtZero: true, max: 100 },
                    x: { display: true }
                }
            }
        });
    } else {
        chart.data.labels = xValues;
        chart.data.datasets[0].data = yValues;
        chart.update('none');
    }
};

// Aggiunto Header JSON per la POST
function sendData(controlType, valveLevel, waterLevel, state) {
    const data = { controlType, valveLevel, waterLevel, state };
    fetch(CUS_URL + "/api/data", {
        method: "POST",
        mode: "cors",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data)
    }).catch(err => console.error("Send failed", err));
}

document.addEventListener("DOMContentLoaded", () => {
    updateDashboard();
    setInterval(updateDashboard, 1000);
});
