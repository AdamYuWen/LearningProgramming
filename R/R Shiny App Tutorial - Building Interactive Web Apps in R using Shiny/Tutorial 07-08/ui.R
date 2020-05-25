library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Iris Dataset", align = "center")),
  sidebarLayout(
    sidebarPanel(
      # Tutorial 07
      # choice: change option values to integers
      selectInput("var", "1. Select the varialbe from the iris dataset",
                  choices = c("Sepal.Length" = 1, "Sepal.Width" = 2,
                              "Petal.Length" = 3, "Petal.Width" = 4),
                  selected = 1),
      br(),
      sliderInput("bins", "2. Select the number of BINs for histogram",
                  min = 5, max = 25, value = 15),
      br(),
      radioButtons("color", "3. Select the color of histogram",
                   choices = c("Green", "Red", "Yellow"), selected = "Green")
    ),
    mainPanel(
      # Tutorial 08
      # Create tabs for showing outputs.
      tabsetPanel(type = "tab",
                  tabPanel("Summary", verbatimTextOutput("my_summary")),
                  tabPanel("Structure", verbatimTextOutput("str")),
                  tabPanel("Data", tableOutput("data")),
                  tabPanel("Plot", plotOutput("my_hist")))
    )
  )
))
