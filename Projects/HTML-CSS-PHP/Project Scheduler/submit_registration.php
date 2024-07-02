<?php
$servername = "database-1.cteu8yg0q1e5.us-east-1.rds.amazonaws.com";
$username = "root";
$password = "Far46how!";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$firstName = $_POST['firstName'];
$lastName = $_POST['lastName'];
$studentID = $_POST['studentID'];
$projectTitle = $_POST['projectTitle'];
$email = $_POST['email'];
$phoneNumber = $_POST['phoneNumber'];
$timeslot = $_POST['timeslot'];
list($startTime, $endTime) = explode('|', $timeslot);

if (!preg_match("/^[A-Za-z]+$/", $firstName) || !preg_match("/^[A-Za-z]+$/", $lastName)) {
    die("First and last name must contain only letters.");
}

if (!preg_match("/^\d{8}$/", $studentID)) {
    die("Student ID must be 8 digits.");
}

if (!preg_match("/^[a-zA-Z0-9]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/", $email)) {
    die("Invalid email format.");
}

if (!preg_match("/^\d{3}-\d{3}-\d{4}$/", $phoneNumber)) {
    die("Phone number must be in the form 999-999-9999.");
}

$sql = "SELECT slotID FROM project.RegistrationSlots 
        WHERE startTime = '$startTime' AND endTime = '$endTime' AND studentID IS NULL LIMIT 1";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    $row = $result->fetch_assoc();
    $slotID = $row['slotID'];

    $sql = "UPDATE project.RegistrationSlots 
            SET studentID = '$studentID', firstName = '$firstName', lastName = '$lastName', title = '$projectTitle', email = '$email', phoneNumber = '$phoneNumber' 
            WHERE slotID = '$slotID'";

    if ($conn->query($sql) === TRUE) {
        $success = true;
    } else {
        $success = false;
    }
} else {
    $success = false;
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Registration Success</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <?php if ($success): ?>
            <h1>Registration Successful</h1>
            <p>Thank you for registering, <?php echo htmlspecialchars($firstName) . ' ' . htmlspecialchars($lastName); ?>.</p>
            <button onclick="window.location.href='index.php'">Return Home</button>
        <?php else: ?>
            <h1>Registration Failed</h1>
            <p>There was an issue with your registration. Please try again.</p>
            <button onclick="window.location.href='register.php'">Try Again</button>
        <?php endif; ?>
    </div>
</body>
</html>