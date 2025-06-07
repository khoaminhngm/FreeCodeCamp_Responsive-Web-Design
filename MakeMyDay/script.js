// Highlight Current Step
const instructionList = document.getElementById('instruction-list');
const steps = document.querySelectorAll('.instruction-step');

// Simulate "current step" highlight
let currentStepIndex = 0;

function highlightCurrentStep() {
  steps.forEach((step, index) => {
    if (index === currentStepIndex) {
      step.classList.add('current-step');
    } else {
      step.classList.remove('current-step');
    }
  });
}

highlightCurrentStep();

// Move to the next step
instructionList.addEventListener('click', () => {
  if (currentStepIndex < steps.length - 1) {
    currentStepIndex++;
    highlightCurrentStep();
  }
});

// Recalculate Route Animation
const recalculateBtn = document.getElementById('recalculate-btn');

recalculateBtn.addEventListener('click', () => {
  recalculateBtn.innerText = 'Recalculating...';
  recalculateBtn.disabled = true;

  // Simulate a recalculation delay
  setTimeout(() => {
    recalculateBtn.innerText = 'Recalculate Route';
    recalculateBtn.disabled = false;

    // Reset steps
    currentStepIndex = 0;
    highlightCurrentStep();
  }, 2000);
});
