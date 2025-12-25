document.addEventListener('DOMContentLoaded', () => {
    const controlType = document.getElementById('controlTypeInput');
    const controllerContainer = document.getElementById('controllerContainer');
    const valveInput = document.getElementById('valveLevelInput');
    const submitBtn = document.querySelector('#controllerForm button[type="submit"]');

    if (!controlType || !controllerContainer || !valveInput) return;

    function updateUI() {
        const isAuto = controlType.value === 'auto';
        if (isAuto) {
            controllerContainer.classList.add('d-none');
            valveInput.disabled = true;
            if (submitBtn) submitBtn.disabled = true;
        } else {
            controllerContainer.classList.remove('d-none');
            valveInput.disabled = false;
            if (submitBtn) submitBtn.disabled = false;
        }
    }

    controlType.addEventListener('change', updateUI);

    updateUI();
});
