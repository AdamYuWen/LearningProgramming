library(shiny)
library(ggplot2)

shinyServer(function(input, output) {
  # selection includes column names of datasets.
  selection <- reactive({
    switch(input$dataset,
           "iris" = names(iris),
           "mtcars" = names(mtcars),
           "trees" = names(trees))
  })

  # Get the input from UI, then desplay more inputs.
  # x_select is for ui.R.
  # x_input is for getting the user input for X.
  output$x_select <- renderUI({
    selectInput(inputId = "x_input",
                label = "Select the First (X) varialbe",
                choices = selection())
  })

  output$y_select <- renderUI({
    selectInput(inputId = "y_input",
                label = "Select the First (Y) varialbe",
                choices = selection())
  })

  output$my_plot <- renderPlot({
    # Use "get" to change values from character to numeric.
    attach(get(input$dataset))
    plot(x = get(input$x_input), y = get(input$y_input),
         xlab = input$x_input, ylab = input$y_input)
  })
})
