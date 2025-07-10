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

function playDotSound() {
	playSound(0.3);
}

function playDashSound() {
	playSound(0.9);
}
function sleep(ms) {
  const start = Date.now();
  while (Date.now() - start < ms) {
    // Busy wait
  }
}

button.addEventListener("click", function() {
	element.textContent="soundIsWorking + brunoPassport";
	randomise();
	playLetter();
});

function playSound(duration) {
const oscillator = audioContext.createOscillator();
oscillator.type = "sine"; // or "square", "triangle", "sawtooth"
oscillator.frequency.value = 440; // Frequency in Hz
oscillator.connect(audioContext.destination);
//const gainNode = audioContext.createGain();
//gainNode.gain.value = 0.5; // Volume multiplier (0.0 to 1.0)

	oscillator.start();
	oscillator.stop(audioContext.currentTime + duration); // Stop after three seconds
}

let morseValues = { 1: "•-", 2: "-•••", 3: "-•-•" };

// Global variable
let pseudoRandom = 0, sleepValue = 0;

function randomise() {
	pseudoRandom = Math.floor(Math.random() * 3) + 1;
}
function playLetter() {
	for (let i = 0; i < morseValues[pseudoRandom].length; i++) {
		if (morseValues[pseudoRandom][i] == '•') {
			if (morseValues[pseudoRandom][i - 1] == '•') sleepValue = 300; 
			else sleepValue = 900;
			console.log("(no. %d delay = %d) • ", pseudoRandom, sleepValue); 
			playDotSound()
			sleep(sleepValue);
		}
		else if (morseValues[pseudoRandom][i] == '-') {
			if (morseValues[pseudoRandom][i - 1] == '-') sleepValue = 300; 
			else sleepValue = 900;
			console.log("(no. %d delay = %d) ---", pseudoRandom, sleepValue); 
			playDashSound()
			sleep(sleepValue);
		}
	}
}



