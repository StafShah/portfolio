<?php
$servername = "database-1.cteu8yg0q1e5.us-east-1.rds.amazonaws.com";
$username = "root";
$password = "Far46how!";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT studentID, firstName, lastName, title, email, phoneNumber, startTime, endTime FROM project.RegistrationSlots WHERE studentID IS NOT NULL";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html lang="en">
<link rel="stylesheet" href="styles.css">
<head>
    <meta charset="UTF-8">
    <title>Student Registration</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Student Registration</h1>
    <p>Welcome to the student project registration page. Below is a list of all registered students.</p>

    <table border="1">
        <tr>
            <th>Student ID</th>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Project Title</th>
            <th>Email</th>
            <th>Phone Number</th>
            <th>Timeslot</th>
        </tr>
        <?php
        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "<tr>";
                echo "<td>" . $row["studentID"] . "</td>";
                echo "<td>" . $row["firstName"] . "</td>";
                echo "<td>" . $row["lastName"] . "</td>";
                echo "<td>" . $row["title"] . "</td>";
                echo "<td>" . $row["email"] . "</td>";
                echo "<td>" . $row["phoneNumber"] . "</td>";
                echo "<td>" . $row["startTime"] . " - " . $row["endTime"] . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='7'>No registered students</td></tr>";
        }
        $conn->close();
        ?>
    </table>

    <p><a href="register.php">Register for a project</a></p>
</body>
</html>
