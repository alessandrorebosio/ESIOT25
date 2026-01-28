
/**
 * Main initialization function that runs when the DOM is fully loaded
 * Sets up event listeners and periodic data refreshing
 */
document.addEventListener('DOMContentLoaded', () => {
    const controllerForm = document.getElementById('controllerForm');
    const controlType = document.getElementById('controlTypeInput');
    const controllerContainer = document.getElementById('controllerContainer');
    const valveInput = document.getElementById('valveLevelInput');
    const submitBtn = document.querySelector('#controllerForm button[type="submit"]');
    const waterCtx = document.getElementById('waterLevelTrend');
    const systemStateEl = document.getElementById('systemState');
    const valveValueEl = document.getElementById('valveValue');

    if (!controlType || !controllerContainer || !valveInput) return;

    /**
     * Updates the UI based on the current control type selection
     * Hides/shows manual controller and disables/enables inputs
     */
    const updateUI = () => {
        const isAuto = controlType.value === 'auto';
        controllerContainer.style.display = isAuto ? 'none' : 'block';
        valveInput.disabled = isAuto;
        if (submitBtn) submitBtn.disabled = isAuto;
    };

    /**
     * Event handler for control type changes
     * @param {Event} e - The change event
     */
    controlType.addEventListener('change', async function () {
        updateUI();
        if (this.value === 'auto') {
            window.alert('You have successfully changed the control type to automatic. The system will now be controlled by the water level sensor.');
            try { 
                await sendData('SWITCH_TO_AUTO', -1, -1, ''); 
            } catch (e) { 
                console.error(e); 
            }
            await loadData();
        }
    });

    /**
     * Form submission handler for manual control
     * @param {Event} e - The submit event
     */
    if (controllerForm) {
        controllerForm.addEventListener('submit', async e => {
            e.preventDefault();
            try {
                await sendData('SET', valveInput.value, -1, '');
                await loadData();
            } catch (err) { 
                console.error(err); 
            }
        });
    }

    /**
     * Loads and displays the latest data from the server
     * Updates the chart, system state, and valve value display
     */
    async function loadData() {
        try {
            const raw = await fetchData();
            const data = Array.isArray(raw) ? raw.filter(el => el.controlType === 'DATA') : [];
            if (!data.length) return;
            
            plotDataHistory(data, waterCtx);
            
            if (systemStateEl) {
                systemStateEl.innerText = 'State of System: ' + data[0].state;
            }
            
            if (valveValueEl) {
                valveValueEl.innerText = 'Valve Opening Level: ' + data[0].valveLevel;
            }
        } catch (error) {
            console.error('There was a problem with the fetch operation:', error);
        }
    }

    updateUI();
    loadData();
    
    const refreshInterval = 10000;
    setInterval(loadData, refreshInterval);
});
