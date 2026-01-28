
const BASE_PATH = "http://localhost:8080";

/**
 * Fetches data from the server API endpoint
 * @returns {Promise<Object>} A promise that resolves with the parsed JSON response
 * @throws {Error} If the network response is not ok
 */
function fetchData() {
    return fetch(BASE_PATH + "/api/data", { method: 'GET', mode: 'cors' })
        .then(res => {
            if (!res.ok) throw new Error('Network response was not ok');
            return res.json();
        });
}

/**
 * Sends control data to the server API endpoint
 * @param {string} controlType - Type of control command ('SWITCH_TO_AUTO', 'SET', etc.)
 * @param {number} valveLevel - Valve opening level (-1 for no change)
 * @param {number} waterLevel - Water level (-1 for no change)
 * @param {string} state - System state description
 * @returns {Promise<Response>} A promise that resolves with the fetch Response
 */
function sendData(controlType, valveLevel, waterLevel, state) {
    const data = {
        controlType: controlType,
        valveLevel: valveLevel,
        waterLevel: waterLevel,
        state: state
    };

    return fetch(BASE_PATH + "/api/data", {
        method: "POST",
        mode: "cors",
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(data)
    });
}

window.fetchData = fetchData;
window.sendData = sendData;
