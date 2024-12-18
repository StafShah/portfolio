var moves = 0;
var timerInterval;
var seconds = 0;
var minutes = 0;
var shuffling = false;

function startTimer() {
    timerInterval = setInterval(function() {
        seconds++;
        if (seconds === 60) {
            seconds = 0;
            minutes++;
        }
        updateTimerDisplay();
    }, 1000);
}

function updateTimerDisplay() {
    var timerDisplay = document.getElementById("timer");
    timerDisplay.textContent = "Time: " + formatTime(minutes) + ":" + formatTime(seconds);
}

function formatTime(time) {
    return time < 10 ? "0" + time : time;
}

function updateMovesDisplay() {
    var movesDisplay = document.getElementById("moves");
    movesDisplay.textContent = "Moves: " + moves;
}

function swapTiles(cell1, cell2) {
    var temp = document.getElementById(cell1).className;
    document.getElementById(cell1).className = document.getElementById(cell2).className;
    document.getElementById(cell2).className = temp;
    moves++;
	if(shuffling == false) {
		updateMovesDisplay();
	}
}

function shuffle() {
    clearInterval(timerInterval);
    seconds = 0;
    minutes = 0;
    startTimer();
    updateTimerDisplay();
	shuffling = true;
	
    for (var row = 1; row <= 4; row++) {
        for (var col = 1; col <= 4; col++) {
            var row2 = Math.floor(Math.random() * 4 + 1);
            var col2 = Math.floor(Math.random() * 4 + 1);
            swapTiles("cell" + row + col, "cell" + row2 + col2);
        }
    }
	
	shuffling = false;
	moves = 0;
}

function simpleGame() {
    clearInterval(timerInterval);
    seconds = 0;
    minutes = 0;
    startTimer();
    updateTimerDisplay();
	shuffling = true;
	
	var choice = Math.floor(Math.random() * 2 + 1);
	switch (choice) {
		case 1:
			swapTiles("cell34", "cell44");
			break;
		case 2:
			swapTiles("cell43", "cell44");
			break;
	}
	
	shuffling = false;
	moves = 0;
}

function checkWin() {
    var win = true;
	var iter = 1;
	
    for (var i = 1; i <= 4; i++) {
		for (var j = 1; j <=4; j++) {
			if(document.getElementById("cell"+i+j).className !== "tile"+iter) {
				win = false;
				return win;
			}
			iter += 1;
		}
    }
    return win;
}

function showWinPopup() {
    clearInterval(timerInterval);
    var movesText = document.getElementById("moves").textContent;
    var timerText = document.getElementById("timer").textContent;
    window.alert("Congratulations! You won in " + movesText.split(":")[1].trim() + " moves and " + timerText + ". Click the OK button to play again.");
	window.location.reload();
}

function clickTile(row, col) {
    var cell = document.getElementById("cell" + row + col);
    var tile = cell.className;

    if (tile !== "tile16") {
        if (col < 4 && document.getElementById("cell" + row + (col + 1)).className === "tile16") {
            swapTiles("cell" + row + col, "cell" + row + (col + 1));
        } else if (col > 1 && document.getElementById("cell" + row + (col - 1)).className === "tile16") {
            swapTiles("cell" + row + col, "cell" + row + (col - 1));
        } else if (row > 1 && document.getElementById("cell" + (row - 1) + col).className === "tile16") {
            swapTiles("cell" + row + col, "cell" + (row - 1) + col);
        } else if (row < 4 && document.getElementById("cell" + (row + 1) + col).className === "tile16") {
            swapTiles("cell" + row + col, "cell" + (row + 1) + col);
        }
    }

    if (checkWin() == true) {
        setTimeout(() => {showWinPopup()}, 1000);
    }
}
