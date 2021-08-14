<?php
    $conn =  mysqli_connect("localhost", "root", "111111", "web3");


    $sql_select = "select * from topic";
    $result = mysqli_query($conn, $sql_select);
    $list = '';
    while ($result_row = mysqli_fetch_array($result)) {
        $escaped = htmlspecialchars($result_row['title']);
        $list = $list.'<li>'.'<a href="index.php?id='.$result_row['id'].'">'.$escaped.'</a>'.'</li>';
        // $list = $list."<li><a href=\"index.php?id={$result_row['id']}\">{$result_row['title']}</a></li>"
    }

    $welcome_text = "Lorem ipsum dolor sit amet consectetur, adipisicing elit. Autem, doloremque id assumenda non suscipit illo tenetur deserunt iusto dolore! Quo beatae laborum at assumenda tenetur quas eos eum molestias qui?";

    $description = array(
        'title' => "welcome",
        'description' => $welcome_text
    );
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
    <form action="process_create.php" method="POST">
        <p><input type="text" name="title" placeholder="title"></p>
        <p><textarea name="description" placeholder="description" cols="30" rows="10"></textarea></p>
        <p><input type="submit"></p>
    </form>

</body>
</html>