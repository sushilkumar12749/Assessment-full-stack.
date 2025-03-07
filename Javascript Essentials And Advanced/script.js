// Check if dark mode was previously enabled
document.addEventListener("DOMContentLoaded", function () {
    if (localStorage.getItem("darkMode") === "enabled") {
        document.body.classList.add("dark-mode");
    }
});

// Toggle dark mode
document.getElementById("dark-mode-toggle").addEventListener("click", function () {
    document.body.classList.toggle("dark-mode");
    localStorage.setItem("darkMode", document.body.classList.contains("dark-mode") ? "enabled" : "disabled");
});

// Load todos from localStorage
function loadTodos() {
    return JSON.parse(localStorage.getItem("todos")) || [];
}

// Save todos to localStorage
function saveTodos(todos) {
    localStorage.setItem("todos", JSON.stringify(todos));
}

// Add new todo
function addTodoItem(todoText, save = true) {
    let list = document.getElementById("todo-list");
    let li = document.createElement("li");
    li.textContent = todoText;
    li.draggable = true; // Enable drag & drop
    li.classList.add("draggable");

    // Create delete button
    let deleteBtn = document.createElement("button");
    deleteBtn.textContent = "❌";
    deleteBtn.addEventListener("click", function () {
        li.classList.add("fade-out");
        setTimeout(() => {
            list.removeChild(li);
            let todos = loadTodos().filter(todo => todo !== todoText);
            saveTodos(todos);
        }, 300);
    });

    li.appendChild(deleteBtn);
    list.appendChild(li);

    // Save new todo if not loaded from storage
    if (save) {
        let todos = loadTodos();
        todos.push(todoText);
        saveTodos(todos);
    }

    // Drag & Drop Events
    li.addEventListener("dragstart", () => li.classList.add("dragging"));
    li.addEventListener("dragend", () => li.classList.remove("dragging"));
}

// Add todo event
document.getElementById("add-btn").addEventListener("click", function () {
    let inputField = document.getElementById("todo-input");
    let todoText = inputField.value.trim();
    if (todoText) {
        addTodoItem(todoText);
        inputField.value = ""; // Clear input
    }
});

// Load existing todos
document.addEventListener("DOMContentLoaded", function () {
    loadTodos().forEach(todo => addTodoItem(todo, false));
});

// Drag & Drop functionality
document.getElementById("todo-list").addEventListener("dragover", function (e) {
    e.preventDefault();
    let dragging = document.querySelector(".dragging");
    let afterElement = getDragAfterElement(e.clientY);
    if (afterElement == null) {
        this.appendChild(dragging);
    } else {
        this.insertBefore(dragging, afterElement);
    }
});

// Helper function for drag position
function getDragAfterElement(y) {
    let listItems = [...document.querySelectorAll(".draggable:not(.dragging)")];
    return listItems.reduce((closest, child) => {
        let box = child.getBoundingClientRect();
        let offset = y - box.top - box.height / 2;
        return offset < 0 && offset > closest.offset ? { offset, element: child } : closest;
    }, { offset: Number.NEGATIVE_INFINITY }).element;
}
