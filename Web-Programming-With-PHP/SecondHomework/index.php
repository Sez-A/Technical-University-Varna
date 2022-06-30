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
        <?php

        abstract class Vehicle {

            protected $yearOfManufacture;

            protected function getYearOfManufacture() {
                return $this->yearOfManufacture;
            }
        }

        class Car extends Vehicle {

            private $type;

            function __construct($t, $year) {
                $this->type = $t;
                $this->yearOfManufacture = $year;
            }

            function parking_price() {
                if ($this->type == "sedan" || $this->type == "cabrio") {
                    return 2 * $this->getYearOfManufacture();
                } else if ($this->type == "station wagon") {
                    return 3 * $this->getYearOfManufacture();
                }
            }

        }

        class Bus extends Vehicle {

            private $maxPassengerCapacity;

            function __construct($mpc, $year) {
                $this->maxPassengerCapacity = $mpc;
                $this->yearOfManufacture = $year;
            }

            function parking_price() {
                return $this->maxPassengerCapacity * $this->yearOfManufacture;
            }

        }

        class Parking {

            private $parking;
            private $maxSpots;

            public function __construct($maxSpots, $parking = []) {
                $this->parking = $parking;
                $this->maxSpots = $maxSpots;
            }

            public function addVehicle($vehicle) {
                if (count($this->parking) < $this->maxSpots) {
                    array_push($this->parking, $vehicle);
                } else {
                    echo "<h2>At the moment we don't "
                    . "have free spots for more vehicles in our parking</h2><br>";
                }
            }

            public function getParking() {
                return $this->parking;
            }

            public function removeVehicle() {
                $removed = array_pop($this->parking);
                return $this->parking;
            }

            public function calculateTurnover() {
                $turnover = 0;
                foreach ($this->parking as $value) {
                    $turnover += $value->parking_price();
                }
                return $turnover;
            }

        }

        $car = new Car("sedan", 2005);
        $bus = new Bus(10, 2000);
        $noMoreSpaceVehicle = new Car("cabrio", 1997);
        
        $parking = new Parking(2);
        $parking->addVehicle($car);
        $parking->addVehicle($bus);
        $parking->addVehicle($noMoreSpaceVehicle);
        
        echo "<h2>Total turnover with one sedan car with "
        . "manufacture year 2005 and one bus "
        . "with 10 passenger places is: " 
        . $parking->calculateTurnover() . "</h2>";
        
        $parking->removeVehicle();
        echo "<br><h2>Total turnover after delete bus from parking is: " 
        . $parking->calculateTurnover() . "</h2>";
        ?>
    </body>
</html>
