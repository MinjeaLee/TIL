<?php
    function print_title(){
        if(isset($_GET['id'])){
            echo $_GET['id'];
        }
        else{
            echo "welcome";
        }
    }
    function print_content(){
        if(isset($_GET['id'])){
            echo file_get_contents("data/".$_GET['id']);
        }
        else{
            echo "world";
        }
    }
    function print_list(){
        $data_dir = "./data";
        $arr_data = scandir($data_dir);
        for($i = 0; $i < count($arr_data); $i++){
            if($arr_data[$i] == "." || $arr_data[$i] == ".."){
                continue;
            }
            echo "<li><a href=\"index.php?id=$arr_data[$i]\">$arr_data[$i]</a></li>\n";
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>
        <?php
            print_title();
        ?>
    </title>
</head>
<body>
    <h1><a href="index.php">WEB</a></h1>
    <nav>
        <ol>
            <?php
                print_list();
            ?>
        </ol>
    </nav> 
    <a href="create.php">create</a>
    <form action="create_process.php" method="post">
        <p><input type="text" name="title" placeholder="input title"></p>
        <p><textarea name="content"  cols="30" rows="10" placeholder="input content"></textarea></p>
        <p><input type="submit" value="제출"></p>
    </form>
</body>
</html>