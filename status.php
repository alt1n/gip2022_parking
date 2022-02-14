
<head><meta http-equiv="refresh" content="1" > </head>
<link rel="stylesheet" href="main.css">
<div id="navbar"> 
  <ul> 
	<li><a href="status.php">Parking Status</a></li> 
  </ul> 
</div> 

<?php
    $link = mysqli_connect("localhost","faka","Tijger","parkingdbho");
    if($link){
    }else{
        echo "Verbinding mislukt:";
        echo mysqli_connect_error();
    }
    echo '<div class="parkingSlots">';
    echo '<div class="linksC">';
    echo '<table border = "1">
            <tr>';
    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P1"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
   
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    
    echo "</td>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P2"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    echo "</td>";
    echo "</tr>";
    echo "<tr>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P3"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    
    echo "</td>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P4"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    echo "</td>";
    echo "</tr>";
    echo "</div>";
    echo "<tr>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P5"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    
    echo "</td>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P6"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    echo "</td>";
    echo "</tr>";
    echo "<tr>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P7"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    echo "</td>";

	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}

    $query = 'SELECT `Naam`, `Status` FROM `parkingdata` WHERE `Naam` = "P8"';
	$result = mysqli_query($link, $query);
    $row = mysqli_fetch_assoc($result);
    echo "<td>";
    echo "Parking " . substr($row["Naam"], -1). ": ";
    if ($row["Status"] == "1"){
        echo "Bezet <br>";
    }else{
        echo "Leeg <br>";
    }
    
    echo "</td>";
    echo "</tr>";
	if(mysqli_query($link, $query)){
	}else{
		echo "Fout bij het toevoegen:".mysqli_error($link);
	}
    echo "</div>";
?>
