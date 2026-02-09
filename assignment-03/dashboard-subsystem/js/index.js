
const UPDATE_INTERVAL = 2000;

let isConnected = false;

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
    document.getElementById('systemState').textContent = data.state || '—';
    document.getElementById('valveValue').textContent = data.valveLevel || '—';

    document.getElementById('controlTypeInput').value = data.controlType || 'auto';
    if (data.valveLevel !== undefined) {
        document.getElementById('valveLevelInput').value = data.valveLevel;
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
        setConnectionStatus(true);
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

window.addEventListener('DOMContentLoaded', () => {
    initChart();
    setConnectionStatus(false);
    fetchAndUpdate();

    document.getElementById('controlTypeInput').addEventListener('change', toggleValveControl);
    document.getElementById('controllerForm').addEventListener('submit', handleFormSubmit);

    toggleValveControl();
    setInterval(fetchAndUpdate, UPDATE_INTERVAL);
});
