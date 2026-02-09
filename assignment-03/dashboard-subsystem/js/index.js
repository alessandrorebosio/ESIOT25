
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
            if (!res.ok) throw new Error(`Failed to fetch data: ${res.status}`);
            return res.json();
        })
        .then(data => {
            const controllerContainer = document.getElementById("controllerContainer");
            const modeSelector = document.getElementById("modeSelector");

            if (data.state === "UNCONNECTED") {
                document.getElementById("waterLevelValue").textContent = "—";
                document.getElementById("controlTypeInput").disabled = true;
                document.getElementById("valveLevelInput").disabled = true;
                document.querySelector("#controllerForm button[type='submit']").disabled = true;
                modeSelector.style.display = "none";
                controllerContainer.style.display = "none";
            } else {
                document.getElementById("waterLevelValue").textContent = data.waterLevel;
                document.getElementById("controlTypeInput").disabled = false;
                document.getElementById("valveLevelInput").disabled = false;
                document.querySelector("#controllerForm button[type='submit']").disabled = false;
                modeSelector.style.display = "block";

                if (data.state === "AUTOMATIC") {
                    controllerContainer.style.display = "none";
                } else {
                    controllerContainer.style.display = "block";
                }

                dataHistory.push({
                    time: new Date(),
                    waterLevel: parseFloat(data.waterLevel) || 0
                });

                if (dataHistory.length > MAX_DATA_POINTS) {
                    dataHistory.shift();
                }

                plotDataHistory(dataHistory, document.getElementById('waterLevelTrend'));
            }

            document.getElementById("valveValue").textContent = data.valveValue;
            document.getElementById("connectionStatus").textContent = data.state;

            document.getElementById("controlTypeInput").value = data.state;
        })
        .catch(() => {
            document.getElementById("connectionStatus").textContent = "NOT AVAILABLE";

            document.getElementById("controlTypeInput").disabled = true;
            document.getElementById("valveLevelInput").disabled = true;
            document.querySelector("#controllerForm button[type='submit']").disabled = true;
        });
};

document.addEventListener("DOMContentLoaded", () => {
    updateDashboard();

    setInterval(updateDashboard, 1000);
});

const plotDataHistory = (data, ctx) => {
    const xValues = data.map(x => new Date(x.time).toLocaleTimeString());
    const yValues = data.map(y => y.waterLevel);

    // Crea il grafico solo la prima volta
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
                plugins: {
                    legend: {
                        display: false
                    },
                },
                scales: {
                    y: {
                        beginAtZero: true,
                        max: 100,
                        title: {
                            display: true,
                            text: 'Level (%)'
                        }
                    },
                    x: {
                        title: {
                            display: true,
                            text: 'Time'
                        }
                    }
                }
            }
        });
    } else {
        chart.data.labels = xValues;
        chart.data.datasets[0].data = yValues;
        chart.update('none');
    }
}

function sendData(controlType, valveLevel, waterLevel, state) {
    var data = {
        controlType: controlType,
        valveLevel: valveLevel,
        waterLevel: waterLevel,
        state: state
    };

    fetch(CUS_URL + "/api/data", {
        method: "POST",
        mode: "cors",
        body: JSON.stringify(data)
    })
}
