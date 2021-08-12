<?php
    $conn =  mysqli_connect("localhost", "root", "111111", "web3");

    // only 1 row
    echo "<h1>single row</h1>";

    $sql_select = "select * from topic where id = 8";
    $result = mysqli_query($conn, $sql_select);
    var_dump($result);
    $result_row = mysqli_fetch_array($result);
    print_r($result_row);

    echo "<h2>".$result_row['title']."</h2>";
    echo "<p>".$result_row['description']."</p>";


    // all row
    $sql_select = "select * from topic";
    $result = mysqli_query($conn, $sql_select);

    echo "<h1>multi rows</h1>";

    while ($result_row = mysqli_fetch_array($result)) {
        echo "<h2>".$result_row['title']."</h2>";
        echo "<p>".$result_row['description']."</p>";
    }
?>