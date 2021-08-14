<?php
    var_dump($_POST);

    $conn = mysqli_connect("localhost", "root", "111111", "web3");

    $filtered = array(
        'title' => mysqli_real_escape_string($conn, $_POST['title']),
        'description' => mysqli_real_escape_string($conn, $_POST['description'])
    );
    
    $sql = "INSERT INTO topic (title, description, created) values ('{$filtered['title']}', '{$filtered['description']}', now())";
    
    // $sql = "INSERT INTO topic (title, description, created) values ('{$_POST['title']}', '{$_POST['description']}', now())";
    // sql injection Vulnerability => description(', '2002-05-29 00:00:00'); -- )

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