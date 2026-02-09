
const BASE_PATH = "http://localhost:8080";

function fetchData() {
    return fetch(BASE_PATH + "/api/data", { method: 'GET', mode: 'cors' })
        .then(res => {
            return res.json();
        })
}

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
