library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 12b", align = "center")),

  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "dataset",
                  label = "Choose a dataset:",
                  choices = c("iris", "mtcars", "trees")),

      numericInput(inputId = "obs",
                   label = "Number of observations:",
                   value = 6),

      submitButton(text = "Update!"),
      p("In this example, changing the user input (dataset or number of
        obervation) will not reflect in the output until the Update button is
        clicked."),
      p("submitButton is used to control the reactiveness of the change in the
        user input.")
    ),

    mainPanel(
      # h4 change the text to header.
      h4(textOutput("title1")),
      verbatimTextOutput("str"),
      h4(textOutput("title2")),
      tableOutput("view")
    )
  )
))
