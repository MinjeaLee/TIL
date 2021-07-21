<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>array</h1>
    <?php  
        $a = array(1, 2, 3, 4, 5);
        for($i = 0; $i < count($a); $i++){
            echo 'i = '.$i.'<br>';
            echo $a[$i].'<br>';
        }

    ?>  
</body>
</html>