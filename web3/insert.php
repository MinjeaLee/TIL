<?php
    $conn =  mysqli_connect("localhost", "root", "111111", "web3");
    $insert = mysqli_query($conn, "
        INSERT INTO topic (
            title, description, created
            )
        values(
            'Oracle', 'Oracle is ...', now()
        );
    ");  
    if(!$insert){
        echo mysqli_error($conn);
    }
?>