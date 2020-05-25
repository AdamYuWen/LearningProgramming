library(shiny)
# There are some shiny app examples.
# runExample() -- List all available examples.
# runExample("01_hello") -- Show the layout and code.

shinyUI(fluidPage(
  titlePanel("Demostration of textInput widget"),
  sidebarLayout(
    # Tutorial 02 ----------
    # h + number: h3 as title
    sidebarPanel((h3("Enter the personal details")),
                 # Tutorial 03 ----------
                 #  first: variable name
                 #  second: showed text
                 #  third: default value
                 textInput("name", "Enter your name", ""),
                 textInput("age", "Enter your age", ""),
                 # Tutorial 04 ----------
                 # third: option list
                 radioButtons("gender", "Select the gender",
                              list("Male", "Female"), ""),
                 # Tutorial 05 ----------
                 # value: default value
                 # step: step don't have to be integer
                 # animate: move the value one by one
                 sliderInput("num_laptop", "How many laptops do you have?",
                             min = 0, max = 5, value = 2, step = 0.2,
                             animate = TRUE),
                 sliderInput("salary", "What's the range of money you have",
                             min = 0, max = 3000, value = c(200, 1000)),
                 # Tutorial 06 ----------
                 # selectize: another style of dropdown list. default is TRUE
                 # multiple: multiple choice
                 selectInput("state1", "Select your state",
                             c("California", "Florida", "Texas", "New York"),
                             selected = "Texas", selectize = TRUE),
                 selectInput("state2", "Which states do you want to live?",
                             c("California", "Florida", "Texas", "New York"),
                             multiple = TRUE)),
    mainPanel((h3("Personal Information")),
              # output variables from server.R
              textOutput("my_name"),
              textOutput("my_age"),
              textOutput("my_gender"),
              textOutput("num_laptop"),
              textOutput("my_salary"),
              textOutput("my_state1"),
              textOutput("my_state2"))
  )
))
