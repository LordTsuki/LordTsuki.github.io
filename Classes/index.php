<?php

    include("classe/conexao.php");
    
    $consulta = "SELECT * FROM usuario";
    $con = $mysqli->query($consulta) or die ($mysqli->error);

    

?>