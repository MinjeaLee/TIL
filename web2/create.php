<?php
    require_once("lib/print.php");
    require_once("view/top.php");
?> 
    <a href="create.php">create</a>
    <form action="create_process.php" method="post">
        <p><input type="text" name="title" placeholder="input title"></p>
        <p><textarea name="content"  cols="30" rows="10" placeholder="input content"></textarea></p>
        <p><input type="submit" value="submit"></p>
    </form>
<?php
    require("view/bottom.php");
?>