
/**
 * Creates or updates a line chart showing water level history
 * @param {Array<Object>} data - Array of data objects with time and waterLevel properties
 * @param {CanvasRenderingContext2D} ctx - Canvas context for rendering the chart
 */
function plotDataHistory(data, ctx) {
    const xValues = data.map(x => new Date(x.time).toLocaleString());
    const yValues = data.map(y => y.waterLevel);

    try {
        if (ctx && ctx._chartInstance) {
            ctx._chartInstance.destroy();
            ctx._chartInstance = null;
        }
    } catch (e) { 
        /* ignore cleanup errors */ 
    }

    const chart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: xValues,
            datasets: [{
                backgroundColor: 'rgba(0,0,0,0.05)',
                borderColor: 'rgba(0,0,0,0.6)',
                fill: true,
                tension: 0.2,
                data: yValues
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: { 
                legend: { 
                    display: false 
                } 
            },
            scales: { 
                x: { 
                    display: true 
                }, 
                y: { 
                    display: true 
                } 
            }
        }
    });

    ctx._chartInstance = chart;
}

window.plotDataHistory = plotDataHistory;
