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
       
    <form method="POST" action="#">
    Please enter your age: <br />
    <input type="text" name="age" />
    <p />
    Please enter the price: <br/>
    <input type="text" name="price" />
    <br/>
    <br/>
    <input type="submit" name="submit" value="Go" />
    </form> 
        
        <?php
        
        $finalPrice = 0;
        if (isset($_POST['submit'])){ 
           $age = $_POST["age"];
           $price = $_POST["price"];
           if($age <= 6) {
               $price = $price - ($price * 0.5);
              echo "Your age is: $age Price with discount: $price";
           } else if($age >= 65) {
           $price = $price - ($price * 0.5);
           echo "Your age is: $age Price with discount: $price";
         
           }
           else {
               echo "Price without discount: $price";
           }
        }
    
        ?>
    </body>
</html>
