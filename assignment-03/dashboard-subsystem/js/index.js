const CUS_URL = 'http://localhost:8080';

const updateDashboard = () => {
    fetch(CUS_URL + "/api/data", {
        method: 'GET',
        mode: 'cors'
    }).then(res => {
        if (!res.ok) throw new Error(`Status: ${res.status}`);
        return res.json();
    }).then(data => {
        dataHistory.push({ time: new Date(), waterLevel: data.waterLevel });
        if (dataHistory.length > MAX_DATA_POINTS) dataHistory.shift();
        plotDataHistory(dataHistory, document.getElementById('waterLevelTrend'));

        document.getElementById("waterLevelValue").textContent = data.waterLevel;
        document.getElementById("valveValue").textContent = data.valveValue;
        document.getElementById("connectionStatus").textContent = data.state;

        const controlTypeInput = document.getElementById("controlTypeInput");
        if ((data.state === "AUTOMATIC" || data.state === "MANUAL") && controlTypeInput.value !== data.state) {
            controlTypeInput.value = data.state;
        }

        if (data.state === "UNCONNECTED") {
            document.getElementById("modeSelector").style.display = "none";
            document.getElementById("controllerContainer").style.display = "none";
        } else {
            document.getElementById("modeSelector").style.display = "block";
            document.getElementById("controllerContainer").style.display = (controlTypeInput.value === "AUTOMATIC") ? "none" : "block";
        }
    }).catch(() => {
        document.getElementById("connectionStatus").textContent = "NOT AVAILABLE";
        document.getElementById("waterLevelValue").textContent = 0;
        document.getElementById("valveValue").textContent = 0;

        document.getElementById("modeSelector").style.display = "none";
        document.getElementById("controllerContainer").style.display = "none";
    });
};

function sendModeChange(state, valveValue) {
    const submitBtn = document.getElementById("submitBtn");
    const originalText = submitBtn.value;

    submitBtn.disabled = true;
    submitBtn.value = "Updating...";

    const data = { state, valveValue };
    fetch(CUS_URL + "/api/mode", {
        method: "POST",
        mode: "cors",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data)
    })
        .then(res => {
            if (!res.ok) throw new Error(`Status: ${res.status}`);
            submitBtn.value = "✓ Updated!";
            setTimeout(() => {
                submitBtn.value = originalText;
                submitBtn.disabled = false;
            }, 1500);
        })
        .catch(err => {
            console.error("Send failed", err);
            submitBtn.value = "✗ Error";
            setTimeout(() => {
                submitBtn.value = originalText;
                submitBtn.disabled = false;
            }, 1500);
        });
}

document.addEventListener("DOMContentLoaded", () => {
    document.getElementById("controlTypeInput").addEventListener("change", function () {
        if (this.value === "AUTOMATIC") {
            window.alert("You have successfully changed the control type to automatic. The system will now be controlled by the water level sensor.");
        }
        document.getElementById("controllerContainer").style.display = (this.value === "AUTOMATIC") ? "none" : "block";
        sendModeChange(this.value, "-1");
    });

    document.getElementById("controllerForm").addEventListener("submit", (event) => {
        event.preventDefault();
        sendModeChange(document.getElementById("controlTypeInput").value, document.getElementById("valveLevelInput").value);
    });

    updateDashboard();
    setInterval(updateDashboard, 1000);
});
