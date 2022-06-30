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
        <form method="POST" action="#">
            Name: <br />
            <input type="text" name="name" /> <br/>
            Family: <br />
            <input type="text" name="family" /> <br/>
            Email: <br /> 
            <input type="text" name="email" /><br/>
            Choose a course: <br /> 
            
            <input type="radio" id="php" name="course" value="PHP">
            <label for="php">PHP</label><br>
            <input type="radio" id="lisp" name="course" value="Lisp">
            <label for="lisp">Lisp</label><br>
            <input type="radio" id="perl" name="course" value="Perl">
            <label for="perl">Perl</label><br>
            <input type="radio" id="unix" name="course" value="Unix">
            <label for="unix">Unix</label><br>
            Aditional information for you? <br />
            <textarea name="about" rows="4" cols="50">

            </textarea>
            <br/>
              <input type="checkbox" name="confirm"
               checked>
            <label for="confirm">Confirm the reciving of the information</label>
            <br/>
            <input type="submit" name="submit" value="Submit" />
              <input type="reset" name="reset" value="Reset" />
        </form>
        <?php
        if (isset($_POST['submit'])){ 
            
           $name = $_POST['name'];
           $family = $_POST['family'];
           $choice = $_POST['course'];
           echo "<br/>Hello, $name $family!<br/>";
           echo "Your choice is $choice";
        }
        ?>
    </body>
</html>
