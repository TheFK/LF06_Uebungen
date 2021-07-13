<?php
$image = imagecreatefromjpeg("test.jpg");
$width = imagesx($image);
$height = imagesy($image);
$pixels = [];
$new_pixels = [];

for ($y = 0; $y < $height; $y++)
{
    for ($x = 0; $x < $width; $x++)
    {
        $pixel = imagecolorat($image, $x, $y);
        $pixels[$x][$y] = $pixel;
    }
}

if(isset($_POST["range"])){
    $range = $_POST["range"];
}
else{
    $range = 2;
}

for ($y = 0; $y < $height; $y++){
    for ($x = 0; $x < $width; $x++){
        $environment = [];
        for ($i = (-1 * $range); $i < $range; $i++){
            for ($j = (-1 * $range); $j < $range; $j++){
                if($i !== 0 || $j !== 0){
                    $environment[] = $pixels[$x + $j][$y + $i];
                }
            }
        }

        sort($environment);
        if(count($environment) % 2 === 0){
            $index = count($environment)/2;
            $index = floor($index);
            $new_pixels[$x][$y] = $environment[$index];
        }
        else{
            $index = count($environment)/2;
            $index = floor($index) + 1;
            $new_pixels[$x][$y] = $environment[$index];
        }
    }
}

for ($y = 0; $y < $height; $y++){
    for ($x = 0; $x < $width; $x++){
        imagesetpixel($image , $x , $y , $new_pixels[$x][$y]);
    }
}

imagejpeg($image, "test_median.jpg");

$html = file_get_contents("content.html");
$html = str_replace("%range%", $range, $html);
echo $html;