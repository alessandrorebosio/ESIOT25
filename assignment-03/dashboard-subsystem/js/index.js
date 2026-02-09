
const CUS_URL = 'http://localhost:8080';

document.addEventListener("DOMContentLoaded", () => {
    fetch(CUS_URL + "/api/data", {
        method: 'GET',
        mode: 'cors'
    })
        .then(res => {
            if (!res.ok) throw new Error(`Failed to fetch data: ${res.status}`);
            return res.json();
        })
        .then(data => {
            document.getElementById("waterLevelValue").textContent = data.waterLevel;
            document.getElementById("valveValue").textContent = data.valveValue;
            document.getElementById("connectionStatus").textContent = data.state;
            console.log(data)
        })
        .catch(() => {
            document.getElementById("connectionStatus").textContent = "NOT AVAILABLE";

            document.getElementById("controlTypeInput").disabled = true;
            document.getElementById("valveLevelInput").disabled = true;
            document.querySelector("#controllerForm button[type='submit']").disabled = true;
        });
});

const plotDataHistory = (data, ctx) => {
    const xValues = data.map(x => new Date(x.time).toLocaleString())
    const yValues = data.map(y => y.waterLevel)

    new Chart(ctx, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                backgroundColor: "rgba(0,0,0,1.0)",
                borderColor: "rgba(0,0,0,0.1)",
                data: yValues
            }]
        },
        options: {
            plugins: {
                legend: {
                    display: false
                },
            },
        }
    });
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
