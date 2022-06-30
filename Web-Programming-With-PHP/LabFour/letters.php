<?php
include 'data.php';
?>
<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
        foreach ($invitations as $name => $eventInfo) {
            echo "<p>";
            echo " Уважаеми (а), " . $name . "<br>";
            foreach ($eventInfo as $event => $constraint) {
                echo "Имаме удоволствието да ви поканим на " . $event . "<br>";
                echo $constraint . "<br>";
            }
            echo "С уважение, Деян Иванов!";
            echo "</p>";
        };
        ?>
    </body>
</html>
