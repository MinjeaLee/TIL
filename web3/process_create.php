<?php
    var_dump($_POST);

    $conn = mysqli_connect("localhost", "root", "111111", "web3");

    $sql = "INSERT INTO topic (title, description, created) values ('{$_POST['title']}', '{$_POST['description']}', now())";

    $create_data = mysqli_query($conn, $sql);

    if(!$create_data){
        echo mysqli_error($conn); 
        //If it is a real service, the error message should not be shown to the user. Error messages need to be logged.
        // error_log(mysqli_error($conn));

        echo "An error occurred while saving.
        Please contact the administrator.";
    }
    else{
        echo "successfully saved<br>";
        echo '<a href="index.php">back</a><br>';
    }
    echo $sql;
?>