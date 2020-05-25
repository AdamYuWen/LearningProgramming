library(shiny)

shinyServer(function(input, output) {
  # Prepare the data that is been selected.
  data <- reactive({
    get(input$dataset)
  })

  output$dat <- renderPrint({
    data()
  })

  # Additional inputs
  output$var_x <- renderUI({
    selectInput(inputId = "variable_x",
                label = "select the X variable",
                choices = names(data()))
  })

  output$var_y <- renderUI({
    selectInput(inputId = "variable_y",
                label = "select the Y variable",
                choices = names(data()))
  })

  output$struct <- renderPrint({
    str(data())
  })

  output$summary <- renderPrint({
    summary(data())
  })

  output$plot <- renderPlot({
    attach(get(input$dataset))
    plot(x = get(input$variable_x), y = get(input$variable_y))
  })
})
