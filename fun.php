<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>function</h1>
    <?php
        $str = "Lorem ipsum dolor sit amet consectetur adipisicing elit. Impedit quis accusantium nesciunt quo error 
        
        voluptate. Esse architecto aspernatur 
        
        quos, impedit, enim asperiores rem, 
         
        voluptates fugiat expedita magnam sed accusamus dignissimos?";
        echo $str;
    ?>
    <h2>strlen()</h2>
    <?php
        echo strlen($str);
    ?>
    <h2>nl2br</h2>
    <?php
        echo nl2br($str);
    ?>
</body>
</html>