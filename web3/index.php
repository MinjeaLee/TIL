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

    $modify_link = '';
    $delete_link = '';

    if(isset($_GET['id'])){
        $filtered_id = mysqli_real_escape_string($conn, $_GET['id']); // security, sql injection attack 

        $sql_show_description = "select * from topic where id = {$filtered_id}"; // sql command
        $result_description = mysqli_query($conn, $sql_show_description); // sql command apply
        $description_arr = mysqli_fetch_array($result_description); // result to arry
        $description = array(
            'title' => htmlspecialchars($description_arr['title']),
            'description' =>  htmlspecialchars($description_arr['description'])
        );
        $modify_link = "<a href=\"modify.php?id={$_GET['id']}\">modify</a>";
        $delete_link = "
        <form action=\"process_delete.php\" method=\"POST\">
            <input type=\"hidden\" name=\"id\" value=\"{$_GET['id']}\">
            <input type=\"submit\" value=\"delete\">
        </form>
        ";
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
    <?=$modify_link?>
    <?=$delete_link?>
    <?php
        echo "<h2>{$description['title']}</h2>";
        echo "<p>{$description['description']}</p>";
    ?>
    
    
</body>
</html>