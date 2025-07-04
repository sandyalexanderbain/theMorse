// Viewable print in inspect cmd+shift+i
console.log("Hello, world");

// Set element variable to store value of greencard
let element = document.getElementById("greencard");
// Change value of greencard to "deportation"
element.textContent="Testing a feature from JS";

let button = document.getElementById("identification");

// Create a new audio environment to handle sound on web.
const audioContext = new AudioContext();
// Debug audioContext
console.log(audioContext);

const oscillator = audioContext.createOscillator();
oscillator.type = "sine"; // or "square", "triangle", "sawtooth"
oscillator.frequency.value = 440; // Frequency in Hz
oscillator.connect(audioContext.destination);
//const gainNode = audioContext.createGain();
//gainNode.gain.value = 0.5; // Volume multiplier (0.0 to 1.0)

button.addEventListener("click", function() {
	element.textContent="soundIsWorking + brunoPassport";
	oscillator.start();
	oscillator.stop(audioContext.currentTime + 0.3); // Stop after three seconds
});
