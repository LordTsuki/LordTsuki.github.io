<?php

include_once('conexao.php')

if ($conn->connect_errno)
{
echo "Falha na conexão: (".$conn->connect_errno.") ".$conn->connect_error;
}
    if(isset($_POST['save']))
    {
        $nome = $_POST['nome'];
        $email = $_POST['email'];
        $senha = $_POST['senha'];
        $credito = $_POST['credito'];

        $sql_query = "INSERT INTO usuario (nome, email, senha, credito)
        VALUES ('$nome', '$email', '$senha', '$credito')";

        if (mysql_query($conn, $sql_query))
        {
            echo "Os valores foram enviados com sucesso!";
        }
        else
        {
            echo "Erro: " . $sql . "" . mysqli_error($conn);
        }
        mysqli_close($conn);
    }
?>