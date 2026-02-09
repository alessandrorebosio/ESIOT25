
const UPDATE_INTERVAL = 2000;

let isConnected = false;
let lastState = null;

function toggleValveControl() {
    const controlType = document.getElementById('controlTypeInput').value;
    const valveControl = document.getElementById('valveLevelControl');

    if (controlType === 'auto') {
        valveControl.style.display = 'none';
    } else {
        valveControl.style.display = 'block';
    }
}

function updateUI(data) {
    const currentState = data.state || '—';
    document.getElementById('systemState').textContent = currentState;
    document.getElementById('valveValue').textContent = (data.valveLevel !== undefined) ? data.valveLevel : '—';

    if (currentState !== lastState) {
        const controlTypeInput = document.getElementById('controlTypeInput');
        if (currentState === 'AUTOMATIC') {
            controlTypeInput.value = 'auto';
        } else if (currentState === 'MANUAL') {
            controlTypeInput.value = 'manual';
        }
        lastState = currentState;
    }

    toggleValveControl();
    updateChart(data.waterLevel);
}

function setConnectionStatus(connected) {
    isConnected = connected;
    const form = document.getElementById('controllerForm');
    const inputs = form.querySelectorAll('input, select, button');

    if (connected) {
        inputs.forEach(input => input.disabled = false);
    } else {
        inputs.forEach(input => input.disabled = true);
        document.getElementById('systemState').textContent = 'NOT AVAILABLE';
    }
}

async function fetchAndUpdate() {
    try {
        const data = await fetchData();
        const hasServer = data && data.state !== undefined;
        setConnectionStatus(!!hasServer);
        updateUI(data);
    } catch (error) {
        setConnectionStatus(false);
    }
}

async function handleFormSubmit(e) {
    e.preventDefault();

    if (!isConnected) {
        alert('Cannot update: not connected to server');
        return;
    }

    const controlType = document.getElementById('controlTypeInput').value;
    const valveLevel = parseInt(document.getElementById('valveLevelInput').value);

    try {
        await sendData(controlType, valveLevel, 0, '');
    } catch (error) {
        console.error('Error sending data:', error);
        alert('Failed to update settings');
    }
}

async function sendCurrentSettings() {
    if (!isConnected) {
        return;
    }

    const controlType = document.getElementById('controlTypeInput').value;
    const valveLevel = parseInt(document.getElementById('valveLevelInput').value);

    try {
        await sendData(controlType, valveLevel, 0, '');
    } catch (error) {
        console.error('Error sending data:', error);
    }
}

function updateValveValueDisplay() {
    const valveLevel = parseInt(document.getElementById('valveLevelInput').value);
    if (!Number.isNaN(valveLevel)) {
        document.getElementById('valveValue').textContent = valveLevel;
    }
}

window.addEventListener('DOMContentLoaded', () => {
    initChart();
    setConnectionStatus(false);
    fetchAndUpdate();

    document.getElementById('controlTypeInput').addEventListener('change', () => {
        toggleValveControl();
        sendCurrentSettings();
    });
    document.getElementById('valveLevelInput').addEventListener('input', () => {
        updateValveValueDisplay();
        sendCurrentSettings();
    });
    document.getElementById('controllerForm').addEventListener('submit', handleFormSubmit);

    toggleValveControl();
    setInterval(fetchAndUpdate, UPDATE_INTERVAL);
});
