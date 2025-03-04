// Function to get cookies by name
function getCookie(name) {
    let cookieArr = document.cookie.split(";");
    for (let cookie of cookieArr) {
        let [cookieName, cookieValue] = cookie.split("=").map(c => c.trim());
        if (cookieName === name) {
            return decodeURIComponent(cookieValue);
        }
    }
    return null;
}

// Function to save To-Do list in cookies
function saveTodos() {
    let todos = [];
    document.querySelectorAll("#todoList li").forEach(li => todos.push(li.textContent));
    document.cookie = `todos=${encodeURIComponent(todos.join(","))}; path=/; max-age=74300`;
}

// Function to load To-Dos from cookies
function loadTodos() {
    let savedTodos = getCookie("todos");
    if (savedTodos) {
        savedTodos.split(",").forEach(todo => addTodoItem(todo));
    }
}

// Function to add a To-Do item to the list
function addTodoItem(todoText) {
    if (todoText.trim() === "") {
        alert("Please enter a valid task!");
        return;
    }

    let li = document.createElement("li");
    li.textContent = todoText;

    // Click to remove item
    li.addEventListener("click", function() {
        this.remove();
        saveTodos();
    });

    document.getElementById("todoList").appendChild(li);
    saveTodos();
}

// Event Listener for adding a To-Do
document.getElementById("addBtn").addEventListener("click", function() {
    let todoInput = document.getElementById("todoInput");
    addTodoItem(todoInput.value);
    todoInput.value = ""; // Clear input field
});

// Event Listener for clearing all To-Dos
document.getElementById("clearBtn").addEventListener("click", function() {
    document.getElementById("todoList").innerHTML = "";
    document.cookie = "todos=; path=/; max-age=0"; // Clear cookies
});

// Load stored To-Dos on page load
window.onload = loadTodos;
