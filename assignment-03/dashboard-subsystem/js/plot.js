
let dataHistory = [];
let chart = null;
const MAX_DATA_POINTS = 10;

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
