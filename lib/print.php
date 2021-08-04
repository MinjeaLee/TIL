<?php
    function print_title(){
        if(isset($_GET['id'])){
            echo htmlspecialchars($_GET['id']);
        }
        else{
            echo "welcome";
        }
    }
    function print_content(){
        if(isset($_GET['id'])){
            $basename = basename($_GET['id']);
            echo htmlspecialchars(file_get_contents("data/".$basename));
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
            $title = htmlspecialchars($arr_data[$i]);
            echo "<li><a href=\"index.php?id=$title\">$title</a></li>\n";
        }
    }
?>