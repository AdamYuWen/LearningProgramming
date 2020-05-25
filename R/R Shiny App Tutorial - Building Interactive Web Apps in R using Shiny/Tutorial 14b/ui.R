library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 14b", align = "center")),

  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "datasets",
                  label = "Choose a dataset:",
                  choices = c("iris", "mtcars", "trees")),

      numericInput(inputId = "obs",
                   label = "Number of observations:",
                   value = 6),

      p("In this example, changing the dataset will update the structure in the
        main panel. However, would not update the observation until the Update
        button is pressed. Basically by using the actionButton along with
        isolate(), we can control the reactiveness of user input at Server
        side"),

      br(),
      # Using HTML and <br/> to change the text in the button.
      actionButton(inputId = "action",
                   label = HTML("Click  update/view the observation<br/>of the
                   selected dataset!")),
      br(),
      p("To partially control the reactiveness at the server side and create
        dependency of reacitivity on the event of pressing the button,
        isolate() is used in the server.R along with actionButton in the ui.R")
    ),

    mainPanel(
      h4(textOutput("title1")),
      verbatimTextOutput("str"),
      h4(textOutput("title2")),
      tableOutput("view")
    )
  )
))
