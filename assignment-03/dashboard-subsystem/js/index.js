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
            dataHistory.push({ time: new Date(), waterLevel: data.waterLevel });
            if (dataHistory.length > MAX_DATA_POINTS) dataHistory.shift();
            plotDataHistory(dataHistory, document.getElementById('waterLevelTrend'));

            document.getElementById("waterLevelValue").textContent = data.waterLevel;
            document.getElementById("connectionStatus").textContent = data.state;
            document.getElementById("valveValue").textContent = data.valveValue;

            const controlTypeInput = document.getElementById("controlTypeInput");
            if (data.state === "AUTOMATIC" || data.state === "MANUAL") {
                if (controlTypeInput.value !== data.state) {
                    controlTypeInput.value = data.state;
                }
            }

            document.getElementById("controllerContainer").style.display =
                (controlTypeInput.value === "AUTOMATIC") ? "none" : "block";
        })
        .catch(() => {
            document.getElementById("connectionStatus").textContent = "NOT AVAILABLE";
            document.getElementById("modeSelector").style.display = "none";
            document.getElementById("controllerContainer").style.display = "none";
            toggleInputs(true);
        });
    document.getElementById("controllerContainer").style.display = (document.getElementById("controlTypeInput").value == "AUTOMATIC") ? "none" : "block";
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

function sendModeChange(state, valveValue) {
    const data = { state, valveValue };
    fetch(CUS_URL + "/api/mode", {
        method: "POST",
        mode: "cors",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data)
    }).catch(err => console.error("Send failed", err));
}

document.addEventListener("DOMContentLoaded", () => {
    document.getElementById("controlTypeInput").addEventListener("change", function () {
        if (this.value === "AUTOMATIC") {
            window.alert("You have successfully changed the control type to automatic. The system will now be controlled by the water level sensor.");
        }
        document.getElementById("controllerContainer").style.display = (this.value === "AUTOMATIC") ? "none" : "block";
        const valveValue = document.getElementById("valveLevelInput").value;
        sendModeChange(this.value, valveValue);
    });

    document.getElementById("controllerForm").addEventListener("submit", (event) => {
        event.preventDefault();
        const controlType = document.getElementById("controlTypeInput").value;
        const valveValue = document.getElementById("valveLevelInput").value;
        document.getElementById("valveValue").textContent = valveValue;
        sendModeChange(controlType, valveValue);
    });

    updateDashboard();
    setInterval(updateDashboard, 1000);
});
