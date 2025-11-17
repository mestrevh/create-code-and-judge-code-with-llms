document.addEventListener("DOMContentLoaded", function () {
    
    const headerPath = window.location.hostname + '/frontend/components/header.html';
    console.log(headerPath)
    fetch(headerPath)
        .then(response => {
            if (!response.ok)
            {
                throw new Error(`Could not load header: ${response.statusText}`);
            }
            return response.text();
        })
        .then (data => {
            document.getElementById('header-placeholder').innerHTML = data;
        })
        .catch(error => {
            console.error('[Header] Error:', error);
            document.getElementById('header-placeholder').innerHTML = '<p style="color:red; text-align:center;">File is not exist ' + headerPath + ' </p>';
        });
});
