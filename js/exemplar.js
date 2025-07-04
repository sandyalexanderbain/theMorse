// Viewable print in inspect cmd+shift+i
console.log("Hello, world");

// Set element variable to store value of greencard
let element = document.getElementById("greencard");
// Change value of greencard to "deportation"
element.textContent="deportation";

let button = document.getElementById("identification");

// Create a new audio environment to handle sound on web.
// Debug audioContext
//console.log(audioContext);

element.textContent="soundIsWorking + brunoPassport";
button.addEventListener("click", function() {
	for (let count = 0; count < 5; count++) {

const audioContext = new AudioContext();
		const oscillator = audioContext.createOscillator();
		oscillator.type = "sine"; // or "square", "triangle", "sawtooth"
		oscillator.frequency.value = 440; // Frequency in Hz
		oscillator.connect(audioContext.destination);
		//const gainNode = audioContext.createGain();
		//gainNode.gain.value = 0.5; // Volume multiplier (0.0 to 1.0)
		console.log("%d", count);
		oscillator.start();
		console.log("%d", count);
		oscillator.stop(audioContext.currentTime + 0.3); // Stop after three seconds
		console.log("%d", count);
	}
});
