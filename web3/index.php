<?php
    $conn =  mysqli_connect("localhost", "root", "111111", "web3");


    $sql_select = "select * from topic";
    $result = mysqli_query($conn, $sql_select);
    $list = '';

    while ($result_row = mysqli_fetch_array($result)) {
        $list = $list.'<li>'.'<a href="index.php?id='.$result_row['id'].'">'.$result_row['title'].'</a>'.'</li>';
    }

    $welcome_text = "Lorem ipsum dolor sit amet consectetur, adipisicing elit. Autem, doloremque id assumenda non suscipit illo tenetur deserunt iusto dolore! Quo beatae laborum at assumenda tenetur quas eos eum molestias qui?";

    $description = array(
        'title' => "welcome",
        'description' => $welcome_text
    );

    if(isset($_GET['id'])){
        
        $sql_show_description = "select * from topic where id = {$_GET['id']}"; // sql command
        $result_description = mysqli_query($conn, $sql_show_description); // sql command apply
        $description_arr = mysqli_fetch_array($result_description); // result to arry
        $description = array(
            'title' => $description_arr['title'],
            'description' =>  $description_arr['description']
        );
    }


?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WEB3</title>
</head>
<body>
    <h1><a href="index.php">WEB</a></h1>
    <ol>
        <?php
            echo $list;
            // var_dump($list);
        ?>
    </ol>
    <a href="create.php">create</a>
    <?php

        echo "<h2>{$description['title']}</h2>";
        echo "<p>{$description['description']}</p>";
   
    ?>
    
</body>
</html>