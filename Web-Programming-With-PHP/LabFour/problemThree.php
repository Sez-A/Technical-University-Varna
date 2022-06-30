<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Project/PHP/PHPProject.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <p>Please enter informatiion:</p>
        <form method="POST" action="#">
            City: <input type="text" name="city">
            Month: <input type="text" name="month">
            Year: <input type="year" name="year">
            <br>
            <p>Please choose the kinds of wheather you experienced from the list below.<br>Choose all that apply</p>
            <input type="checkbox" name="weather[]" value="sunshine" />Sunshine<br>
            <input type="checkbox" name="weather[]" value="clouds" />Clouds<br>
            <input type="checkbox" name="weather[]" value="rain" />Rain<br>
            <input type="checkbox" name="weather[]" value="hail" />Hail<br>
            <input type="checkbox" name="weather[]" value="sleet" />Sleet<br>
            <input type="checkbox" name="weather[]" value="snow" />Snow<br>
            <input type="checkbox" name="weather[]" value="wind" />Wind<br>
            <input type="checkbox" name="weather[]" value="cold" />Cold<br>
            <input type="checkbox" name="weather[]" value="heat" />Heat<br>
            <br>
            <input type="submit" name="submit" value="Submit" />
            <br>
            <br>
        </form>
        <?php
        if (isset($_POST['submit'])) {

            


            $city = $_POST['city'];
            $month = $_POST['month'];
            $year = $_POST['year'];
            echo "In $city in the month of $month $year, you
observed the following weather:";

            if (isset($_POST['weather']) AND is_array($_POST['weather'])) {
                echo "<ul>";
                foreach ($_POST['weather'] as $e) {
                    print"<li>$e</li>";
                }
                echo "<ul/>";
            }
        }
        
        ?>
    </body>
</html>
