<head><meta http-equiv="refresh" content="1" > </head>
<?php
    
    $link = mysqli_connect("localhost","faka","Tijger","parkingdbho");
    if($link){
    }else{
        echo "Verbinding mislukt:";
        echo mysqli_connect_error();
    }
    if (isset($_GET['par1']) and isset($_GET['par2']) and isset($_GET['par3']) and isset($_GET['par4']) and isset($_GET['par5']) and isset($_GET['par6']) and isset($_GET['par7']) and isset($_GET['par8'])  ){
        $Parking1 = $_GET['par1'];
        
        if ($Parking1 == "0"){
            echo "Parking 1: 0";
            $query0 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P1"';

            if(mysqli_query($link, $query0)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 1: 1";
            $query1 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P1"';

            if(mysqli_query($link, $query1)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }

        $Parking2 = $_GET['par2'];

        if ($Parking2 == "0"){
            echo "Parking 2: 0";
            $query2 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P2"';

            if(mysqli_query($link, $query2)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 2: 1";
            $query3 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P2"';

            if(mysqli_query($link, $query3)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }

        $Parking3 = $_GET['par3'];

        if ($Parking3 == "0"){
            echo "Parking 3: 0";
            $query4 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P3"';

            if(mysqli_query($link, $query4)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 3: 1";
            $query5 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P3"';

            if(mysqli_query($link, $query5)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }


        $Parking4 = $_GET['par4'];

        if ($Parking4 == "0"){
            echo "Parking 4: 0";
            $query6 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P4"';

            if(mysqli_query($link, $query6)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 4: 1";
            $query7 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P4"';

            if(mysqli_query($link, $query7)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }


        $Parking5 = $_GET['par5'];

        if ($Parking5 == "0"){
            echo "Parking 5: 0";
            $query8 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P5"';

            if(mysqli_query($link, $query8)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 5: 1";
            $query9 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P5"';

            if(mysqli_query($link, $query9)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }


        $Parking6 = $_GET['par6'];

        if ($Parking6 == "0"){
            echo "Parking 6: 0";
            $query10 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P6"';

            if(mysqli_query($link, $query10)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 6: 1";
            $query11 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P6"';

            if(mysqli_query($link, $query11)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }
        
        $Parking7 = $_GET['par7'];

        if ($Parking7 == "0"){
            echo "Parking 7: 0";
            $query12 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P7"';

            if(mysqli_query($link, $query12)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 7: 1";
            $query13 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P7"';

            if(mysqli_query($link, $query13)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }

        $Parking8 = $_GET['par8'];

        if ($Parking8 == "0"){
            echo "Parking 8: 0";
            $query14 = 'UPDATE `parkingdata` SET `Status`="0" WHERE `Naam`="P8"';

            if(mysqli_query($link, $query14)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
            
        }else{
            echo "Parking 8: 1";
            $query15 = 'UPDATE `parkingdata` SET `Status`="1" WHERE `Naam`="P8"';

            if(mysqli_query($link, $query15)){
                
            }else{
                echo "Fout bij het toevoegen:".mysqli_error($link);
            }
        }

    }else{
        echo "oei";
    }
?>
