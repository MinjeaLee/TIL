<?php
    var_dump($_POST);

    $conn = mysqli_connect("localhost", "root", "111111", "web3");


    settype($_POST['id'], 'integer');

    $filtered = array(
        'id' => mysqli_real_escape_string($conn, $_POST['id'])
    );

    $sql = "DELETE FROM topic where id = {$filtered['id']}";

    $delete_data = mysqli_query($conn, $sql);

    if(!$delete_data){
        echo mysqli_error($conn); 
        //If it is a real service, the error message should not be shown to the user. Error messages need to be logged.
        // error_log(mysqli_error($conn));

        echo "An error occurred while saving.
        Please contact the administrator.";
    }
    else{
        echo "successfully deleted<br>";
        echo '<a href="index.php">back</a><br>';
    }
    echo $sql;
?>