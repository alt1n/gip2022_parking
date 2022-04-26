<head><meta http-equiv="refresh" content="1" > </head>

<link rel="stylesheet" href="main.css">
<div id="navbar"> 
    <ul> 
	<li><a href="status.php">Parking Status</a></li> 
    </ul> 
</div>

<?php
    $aantal = 0;
    
    $link = mysqli_connect("localhost","faka","Tijger","parkingdbho");
    if($link){
    }else{
        echo "Verbinding mislukt:";
        echo mysqli_connect_error();
    }
    echo '<div class="Alles">';
    echo '<div class="ParkingPlaatsen">';
    
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P1"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking1" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking1" style="background-color: darkgreen;">';
    }    
   
    echo "Parking " . substr($row["Naam"], -1). ": ";
   
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P2"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking2" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking2" style="background-color: darkgreen;">';
    } 
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
    
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P3"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking3" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking3" style="background-color: darkgreen;">';
    } 
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
    
    
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P4"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking4" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking4" style="background-color: darkgreen;">';
    } 
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
    
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P5"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking5" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking5" style="background-color: darkgreen;">';
    } 
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
    
    
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P6"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    if ($row["Status"] == "1"){
        echo '<div class="Parking6" style="background-color: darkred;">';
    }else{
        echo '<div class="Parking6" style="background-color: darkgreen;">';
    } 
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
        $aantal = $aantal + 1;
    }else{
        echo "Leeg <br>";
    }
    
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo '</div>';
    echo '</div>';
    
    echo '<div class="Vrije">';
    if ($aantal == 6){
        echo '<h3 style="color:white; font-size:1.5em; display:inline-block; margin-right:10px;" id="vP">Vrije plaatsen: </h3>';
        echo '<h3 style="color:red; background-color: #1f1e1b; display:inline-block; padding:0.5em; font-size:2em;" id="vP">0</h3>';
    }else{
        echo '<h3 style="color:white; font-size:1.5em; display:inline-block; margin-right:10px;" id="vP">Vrije plaatsen: </h3>';
        echo '<h3 style="color:white; background-color: #1f1e1b; display:inline-block; padding:0.5em; font-size:2em;" id="vP">'.(6-$aantal).'</h3>';
    }
    echo '</div>';
    echo '</div>';
?>
