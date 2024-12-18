<?php
$servername = "database-1.cteu8yg0q1e5.us-east-1.rds.amazonaws.com";
$username = "root";
$password = "Far46how!";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT startTime, endTime, 6 - COUNT(studentID) as slots_remaining 
        FROM project.RegistrationSlots 
        GROUP BY startTime, endTime 
        HAVING slots_remaining > 0";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html lang="en">
<link rel="stylesheet" href="styles.css">
<head>
    <meta charset="UTF-8">
    <title>Project Registration Form</title>
    <link rel="stylesheet" href="styles.css">
    <script>
        function validateForm() {
            const firstName = document.forms["regForm"]["firstName"].value;
            const lastName = document.forms["regForm"]["lastName"].value;
            const studentID = document.forms["regForm"]["studentID"].value;
            const email = document.forms["regForm"]["email"].value;
            const phoneNumber = document.forms["regForm"]["phoneNumber"].value;

            const nameRegex = /^[A-Za-z]+$/;
            const idRegex = /^\d{8}$/;
            const emailRegex = /^[a-zA-Z0-9]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
            const phoneRegex = /^\d{3}-\d{3}-\d{4}$/;

            if (!nameRegex.test(firstName)) {
                alert("First name must contain only letters.");
                return false;
            }

            if (!nameRegex.test(lastName)) {
                alert("Last name must contain only letters.");
                return false;
            }

            if (!idRegex.test(studentID)) {
                alert("Student ID must be 8 digits.");
                return false;
            }

            if (!emailRegex.test(email)) {
                alert("Invalid email format.");
                return false;
            }

            if (!phoneRegex.test(phoneNumber)) {
                alert("Phone number must be in the form 999-999-9999.");
                return false;
            }

            return true;
        }
    </script>
</head>
<body>
    <h1>Project Registration Form</h1>

    <form name="regForm" action="submit_registration.php" onsubmit="return validateForm()" method="post">
        <label for="firstName">First Name:</label>
        <input type="text" id="firstName" name="firstName" required><br>

        <label for="lastName">Last Name:</label>
        <input type="text" id="lastName" name="lastName" required><br>

        <label for="studentID">Student ID:</label>
        <input type="text" id="studentID" name="studentID" required><br>

        <label for="projectTitle">Project Title:</label>
        <input type="text" id="projectTitle" name="projectTitle"><br>

        <label for="email">Email:</label>
        <input type="text" id="email" name="email" required><br>

        <label for="phoneNumber">Phone Number:</label>
        <input type="text" id="phoneNumber" name="phoneNumber" required><br>

        <label for="timeslot">Timeslot:</label>
        <select id="timeslot" name="timeslot" required>
            <?php
            if ($result->num_rows > 0) {
                while($row = $result->fetch_assoc()) {
                    echo "<option value='" . $row["startTime"] . "|" . $row["endTime"] . "'>" . $row["startTime"] . " - " . $row["endTime"] . " (" . $row["slots_remaining"] . " slots remaining)</option>";
                }
            }
            $conn->close();
            ?>
        </select><br>

        <input type="submit" value="Register">
    </form>
</body>
</html>
