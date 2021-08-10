<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php  
        $i = 0;
        while(true){
            echo "2<br>";
            $i++;
            if($i > 10){
                break;
            }
        }
        if($i > 10){
            echo "success";
        }
    ?>
</body>
</html>