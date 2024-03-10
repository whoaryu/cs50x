document.addEventListener('DOMContentLoaded', function () {
    alert("Welcome to My Awesome Website!");
    setInterval(function () {
        document.body.style.backgroundColor = getRandomColor();
    }, 2000);
        function getRandomColor() {
        var letters = '0123456789ABCDEF';
        var color = '#';
        for (var i = 0; i < 6; i++) {
            color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
    }
});
