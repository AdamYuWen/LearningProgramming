library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 13a", align = "center")),

  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "dataset",
                  label = "Select the Dataset of your choice",
                  choices = c("iris", "mtcars", "trees"),
                  selected = "iris"),
      br(),
      helpText("The following selectInput drop down choices are dynamically
               populated based on the dataset selected by the user above"),
      br(),
      # Show the output in sidebarPanel, which is also an input.
      uiOutput(outputId = "x_select"),
      br(),
      uiOutput(outputId = "y_select")
    ),

    mainPanel(
      plotOutput("my_plot")
    )
  )
))
