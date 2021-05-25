<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>8</title>
</head>
<body>
    <h1>function</h1>
    <?php 
        $str = "Lorem ipsum dolor, sit amet consectetur adipisicing elit. Blanditiis libero, 
        
        quas dolorem ab nisi atque consectetur fugit sapiente ipsum veritatis!";

        echo $str;
    ?>
    <h2>strlen</h2>
    <?php
        echo strlen($str);
    ?>
    <h2>nl2br</h2>
    <?php
        echo nl2br($str);
    ?>
</body>
</html>